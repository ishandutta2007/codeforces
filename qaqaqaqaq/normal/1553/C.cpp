#include<bits/stdc++.h>
#define int long long

using namespace std;
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

// using namespace std;

const int maxn=300007;


int _;
string s;
signed main(){
    cin>>_;
    while (_--){
        cin>>s;
        int cnt1=0,cnt2=0,rem1=5, rem2=5;
        int ans1=10, ans2=10;
        rep(i,10){
            if (i&1){
                rem1--;
                if (s[i]=='1') cnt1++;
            }
            else{
                rem2--;
                if (s[i]!='0') cnt2++;
            }
            if (rem1+cnt1<cnt2){
                ans1=i+1;
                break;
            }
        }
        rem1=5, rem2=5, cnt1=cnt2=0;
        rep(i,10){
            if (i&1){
                rem1--;
                if (s[i]!='0') cnt1++;
            }
            else{
                rem2--;
                if (s[i]=='1') cnt2++;
            }
            if (rem2+cnt2<cnt1){
                ans2=i+1;
                break;
            }
        }
        cout<<min(ans1,ans2)<<"\n";
    }
    return 0;
}