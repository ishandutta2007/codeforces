#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

string s[3];

pair<bool, char> ok(string s1, string s2){
    int cnt[2];
    cnt[0] = 0;
    cnt[1] = 0;
    for(char x : s1){
        if(x == '1') cnt[0]++;
    }
    for(char x : s2){
        if(x == '1') cnt[1]++;
    }
    int n = s1.size() / 2;
    if(cnt[0] >= n && cnt[1] >= n) return mp(true, '1');
    if(cnt[0] <= n && cnt[1] <= n) return mp(true, '0');
    return mp(false,'0');
}

void solve(){
    int n; cin >> n;
    for(int i=0;i<3;i++) cin>>s[i];
    string ans = "";
    string a,b;
    char zn;
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            pii wyn = ok(s[i], s[j]);
            if(wyn.st){
                a = s[i];
                b = s[j];
                zn = wyn.nd;
            }
        }
    }
    int coming = n;
    int wsk = 0;
    //cout<<endl;
    //cout<<a<<endl<<b<<endl<<zn<<endl;
    for(int i=0;i<n*2;i++){
        if(a[i] == zn && coming){
            while(b[wsk] != zn){
                if(zn == '0') ans += "1";
                else ans += "0";
                wsk++;
            }
            ans += a[i];
            coming--;
            wsk++;
            //cout<<"WA"<<i<<" " << ans<<endl;
            continue;
        }
        else{
            if(wsk == n * 2){
                ans += a[i];
            }
            else{
                ans += a[i];
                if(b[wsk] != a[i] && coming == 0){
                    ans += b[wsk];
                    wsk++;
                }
                else{
                    if(a[i] == b[wsk]) wsk++;
                }

            }
        }
        //cout<<"WA"<<i<<" " << ans<<endl;
    }
    while(wsk < n * 2){
        ans += b[wsk++];
    }
    assert(ans.size() <= n * 3);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}