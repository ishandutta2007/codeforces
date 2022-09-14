#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int a[1010][1010];
int32_t main() {
    int n;cin>>n;
    int cnt=0;
    for (int i=0;i<n/4;i++){
        for (int j=0;j<n/4;j++){
            for (int t=0;t<4;t++){
                for (int q=0;q<4;q++){
                    a[i*4+t][j*4+q]=cnt++;
                }
            }
        }

    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


///2007521364118