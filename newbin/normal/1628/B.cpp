#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int T; cin>>T;
    while(T--){
        map<string, int> l, r;
        int n; cin>>n;
        int flag = 0;
        vector<string> a(n);
        fors(i,0,n){
            string s; cin>>s; a[i] = s;
            if(s.size() == 1) flag = 1;
            else if(s.size() == 2) {
                if(s[0] == s[1]) flag = 1;
            }else{
                assert(s.size() == 3);
                if(s[0]==s[2]) flag = 1;
            }
            if(l.count(s)) l[s] = min(l[s], i);
            else l[s] = i;
            if(r.count(s)) r[s] = max(r[s], i);
            else r[s] = i;
        }
        if(flag) cout<<"YES"<<endl;
        else {

            fors(i,0,n){
                if(flag) break;
                string t = a[i]; reverse(all(t));
                if(r.count(t) && r[t] > i) flag = 1;
                t = "";
                t += a[i][1]; t += a[i][0];
                if(r.count(t) && r[t] > i)  flag = 1;

                t = "";
                t += a[i][2]; t += a[i][1];
                if(l.count(t) && l[t] < i)  flag = 1;
            }
            if(flag) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}