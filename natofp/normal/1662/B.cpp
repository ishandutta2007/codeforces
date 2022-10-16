#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long
#define mt make_tuple
#define pch pair<char, char>

using namespace std;

int cnt[4][28];
int mono[28];
int take1[28];
int take2[28];

bool taken[4][1005];

string s[4];
vector<int> id[4];
int need[4];

void solve(){
    for(int i=1;i<=3;i++) cin >> s[i];
    for(int i=1;i<=3;i++){
        for(char x : s[i]) cnt[i][x - 'A' + 1] += 1;
    }
    int f = 0;
    vector<pch> answer;
    for(int i=1;i<=26;i++){
        f += min(cnt[1][i] + cnt[2][i], cnt[3][i]);
    }
    int biore1 = 0;
    int biore2 = 0;
    for(int i=1;i<=26;i++){
        int cc = cnt[3][i];
        int aa = cnt[1][i];
        int bb = cnt[2][i];
        if(cc >= aa + bb){
            biore1 += cc - (aa + bb);
        }
        else{
            biore2 += min({aa, bb, (aa + bb - cc) / 2});
        }
    }
    int limMono = min(biore1, biore2);
    int gone = 0;
    for(int i=1;i<=26;i++){
        int cc = cnt[3][i];
        int aa = cnt[1][i];
        int bb = cnt[2][i];
        if(cc <= aa + bb){
            int gogo = min({aa, bb, (aa + bb - cc) / 2});
            gogo = min(gogo, limMono - gone);
            gone += gogo;
            mono[i] = gogo;
        }
    }

    for(int i=1;i<=2;i++){
        for(int j=1;j<=26;j++){
            int want = mono[j];
            for(int c=0;c<s[i].size();c++){
                if(want && s[i][c] == 'A' + j - 1){
                    taken[i][c] = true;
                    want--;
                }
            }
        }
    }

    int atMost = min(s[1].size(), s[2].size());
    for(int i=1;i<=26;i++) atMost -= mono[i];

    for(int i=1;i<=26;i++){
        int biere = min(cnt[1][i] + cnt[2][i], cnt[3][i]);
        for(int j=1;j<=2;j++){
            for(int c=0;c<s[j].size();c++){
                if(s[j][c] == 'A' + i - 1 && taken[j][c] == false && biere && atMost){
                    atMost--;
                    biere--;
                    taken[j][c] = true;
                    id[j].pb(c);
                }
            }
        }
    }

    for(int i=1;i<=2;i++){
        int used = 0;
        int kto = 2 - (i == 2);
        for(int c=0;c<s[i].size();c++){
            if(!taken[i][c]){
                if(used < (int)id[kto].size()){
                    taken[i][c] = true;
                    int index = id[kto][used++];
                    answer.pb(mp(s[kto][index], s[i][c]));
                    cnt[3][s[kto][index] - 'A' + 1] -= 1;
                }
            }
        }
    }

    for(int i=1;i<=26;i++){
        int ile = mono[i];
        while(ile--){
            int use = 0;
            for(int j=1;j<=26;j++){
                if(cnt[3][j]){
                    cnt[3][j] -= 1;
                    use = j;
                    break;
                }
            }
            answer.pb(mp('A' + use - 1, 'A' + i - 1));
        }
    }

    for(int i=1;i<=2;i++){
        for(int j=0;j<s[i].size();j++) need[i] += (!taken[i][j]);
    }
    int last = 1;
    int w1 = 0;
    int w2 = 0;
    while(w1 < s[1].size() || w2 < s[2].size()){
        while(w1 < s[1].size() && taken[1][w1]) w1++;
        while(w2 < s[2].size() && taken[2][w2]) w2++;
        while(last <= 26 && cnt[3][last] == 0) last++;
        if(w1 == (int)s[1].size() && w2 == (int)s[2].size()) break;
        if(w1 == (int)s[1].size()){
            if(last != 27){
                answer.pb(mp('A' + last - 1, s[2][w2]));
                w2++;
                cnt[3][last] -= 1;
            }
            else{
                answer.pb(mp('A', s[2][w2]));
                w2++;
            }
        }
        else if (w2 == (int)s[2].size()){
            if(last != 27){
                answer.pb(mp('A' + last - 1, s[1][w1]));
                w1++;
                cnt[3][last] -= 1;
            }
            else{
                answer.pb(mp('A', s[1][w1]));
                w1++;
            }
        }
        else{
            if(last == 27){
                answer.pb(mp(s[1][w1], s[2][w2]));
                w1++;
                w2++;
            }
            else{
                cnt[3][last] -= 1;
                if(need[1] > need[2]){
                    need[1] -= 1;
                    answer.pb(mp('A' + last - 1, s[1][w1]));
                    w1++;
                }
                else{
                    need[2] -= 1;
                    answer.pb(mp('A' + last - 1, s[2][w2]));
                    w2++;
                }
            }
        }
    }
    for(int i=1;i<=26;i++){
        while(cnt[3][i]--) answer.pb(mp('A', 'A' + i - 1));
    }
    cout << answer.size() << "\n";
    for(auto cur : answer){
        cout << cur.st << cur.nd << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}