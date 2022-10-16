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

using namespace std;

int cnt[26];
const int nax = 1e5 + 5;
int ans[nax];

void solve(){
    string s; cin >> s;
    int n = s.length();
    for(int i=0;i<26;i++) cnt[i] = 0;
    for(char x : s){
        cnt[x - 'a']++;
    }
    int uniq = 0;
    for(int i=0;i<26;i++) uniq += (cnt[i] > 0);
    if(uniq == 1){
        cout << s << "\n";
        return;
    }
    bool jeden = true;
    for(int i=0;i<26;i++){
        if(cnt[i] == 1) jeden = false;
    }
    if(jeden){
        // sa 2 i kazdego >= 2
        int id = 0;
        for(int i=0;i<26;i++){
            if(cnt[i] > 0){
                id = i;
                break;
            }
        }

        if(uniq == 2){
            /*ans[0] = id;
            ans[1] = id;
            cnt[id] -= 2;
            */
            int one = id;
            int two = -1;
            for(int i=0;i<26;i++){
                if(i != id && cnt[i] > 0) two = i;
            }

            if(cnt[one] <= cnt[two] + 2){
                ans[0] = id;
                ans[1] = id;
                cnt[id] -= 2;
                for(int j=2;j<n;j++){
                    if((ans[j - 1] != one && cnt[one] > 0) || (cnt[two] == 0)){
                        cnt[one]--;
                        ans[j] = one;
                        continue;
                    }
                    else{
                        ans[j] = two;
                        cnt[two]--;
                    }
                }
            }
            else{
                ans[0] = one;
                for(int i=0;i<cnt[two];i++) ans[i + 1] = two;
                for(int i=cnt[two] + 1;i<n;i++) ans[i] = one;
            }

        }
        else{
            vector<int> ex;
            for(int i=0;i<26;i++){
                if(cnt[i] > 0) ex.pb(i);
            }

            int xd = cnt[ex[0]] - 2;
            if(xd * 2 <= n - 2){
                int id = ex[0];
                ans[0] = id;
                ans[1] = id;
                cnt[id] -= 2;

                for(int j=2;j<n;j++){
                    if(ans[j - 1] != id && cnt[id] > 0){
                        cnt[id]--;
                        ans[j] = id;
                        continue;
                    }
                    else{
                        for(int i=0;i<26;i++){
                            if(i != id && cnt[i] > 0){
                                ans[j] = i;
                                cnt[i]--;
                                break;
                            }
                        }
                    }
                }
            }
            else{
                ans[0] = ex[0];
                ans[1] = ex[1];
                cnt[ex[0]]--;
                cnt[ex[1]]--;
                int done = 2;
                for(int i=0;i<cnt[ex[0]];i++){
                    ans[done++] = ex[0];
                }
                cnt[ex[0]] = 0;
                ans[done++] = ex[2];
                cnt[ex[2]]--;

                for(int j=done;j<n;j++){
                    for(int i=0;i<26;i++){
                        if(i != id && cnt[i] > 0){
                            ans[j] = i;
                            cnt[i]--;
                            break;
                        }
                    }
                }

                //male giga dominua
            }

            /*for(int i=done;i<n;i++){
                for(int j=0;j<26;j++){
                    if(cnt[j] > 0){
                        cnt[j]--;
                        ans[i] = j;
                        break;
                    }
                }
            }*/
        }

        for(int i=0;i<n;i++) cout << (char)('a' + ans[i]);
        cout << "\n";
        return;
    }
    else{
        int id = 0;
        for(int i=0;i<26;i++){
            if(cnt[i] == 1){
                id = i;
                break;
            }
        }
        ans[0] = id;
        cnt[id]--;
        for(int i=1;i<n;i++){
            for(int j=0;j<26;j++){
                if(cnt[j] > 0){
                    cnt[j]--;
                    ans[i] = j;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++) cout << (char)('a' + ans[i]);
        cout << "\n";
        return;
    }
}

void brut(vector<char> s){
    sort(s.begin(), s.end());
    vector<char> res = s;
    int mx = 1e9;
    do{
        int cur = 0;
        for(int i=0;i<s.size();i++){
            for(int len=1;len<=i;len++){
                bool eq = true;
                for(int k=0;k<len;k++){
                    if(s[k] != s[k + i + 1 - len]) eq = false;
                }
                if(eq) cur = max(cur, len);
            }
        }
        //cout << cur << endl;
        //return;
        if((cur < mx) || (min(s, res) == s && cur == mx)){
            mx = cur;
            res = s;
            //cout << "WA" << endl;
        }
    }while(next_permutation(s.begin(), s.end()));
    //cout << mx <<endl;
    for(char x : res){
        cout << x;
    }
    cout << endl;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //vector<char> xdd = {'a','a','b','a','a','c','b','b','c','c'};
    //brut(xdd);
    //return 0;
    //solve("acaaaaaacc");
    //return 0;
     int tt; cin >> tt;
     while(tt--) solve();



    return 0;
}