#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
bool used[10];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    string s;cin>>s;
    for (auto i:s){
        if (i=='L'){
            for (int i=0;i<10;i++) {
                if (!used[i]) {
                    used[i]=true;
                    break;
                }
            }
        } else if (i=='R'){
            for (int i=9;i>=0;i--) {
                if (!used[i]) {
                    used[i]=true;
                    break;
                }
            }
        } else used[i-'0']=false;
    }
    for (int i=0;i<10;i++) cout<<used[i];
    return 0;
}