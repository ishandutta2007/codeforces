#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF=4e18;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;cin>>s;
    if (s.size()%2==1){

        for(int i=1;i<s.size();i++){
            if (s[i]=='1'){
                cout << (s.size())/2+1 <<endl;
                return 0;
            }
        }
    }
    cout << (s.size())/2 <<endl;

    return 0;
}