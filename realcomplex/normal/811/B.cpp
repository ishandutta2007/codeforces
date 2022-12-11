#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main()
{
    int n,m;
    cin >> n >> m;
    int sk[n];
    for(int i = 0;i<n;i++){
        cin >> sk[i];
    }
    int cnt = 0;
    int l,r,in;
    for(int i = 0;i<m;i++){
        cin >> l >> r >> in;
        l--;
        r--;
        in--;
        cnt = 0;
        for(int x = l;x<=r;x++){
            if(sk[x] < sk[in]){
                cnt++;
            }
        }
        if(cnt == (in-l)){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}