#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

void open(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}

int main()
{
    //open();
    int n;
    cin >> n;
    int sk[n];
    int t = 1;
    for(int j = 0;j<n;j++){
        cin >> sk[j];
    }
    sort(sk,sk+n);
    int ans = 1;
    for(int i = 0;i<n;i++){
        if(sk[i]>=t){
            ans++;
            t++;
        }
    }
    cout << ans;
    return 0;
}