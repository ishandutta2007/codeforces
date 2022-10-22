#include <iostream>

using namespace std;

int aa[200002], bb[200002];
int cnta[200002], cntb[200002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int a, b, k;
        long long ans = 0;
        cin >> a >> b >>k;
        for(int i=1;i<=a;i++){
            cnta[i] = 0;
        }
        for(int i=1;i<=b;i++){
            cntb[i] = 0;
        }
        for(int i=1;i<=k;i++){
            cin >> aa[i];
        }
        for(int i=1;i<=k;i++){
            cin >> bb[i];
        }

        for(int i=1;i<=k;i++){
            ans += i - cnta[aa[i]] - cntb[bb[i]] - 1;
            cnta[aa[i]]++;
            cntb[bb[i]]++;
        }

        cout << ans << "\n";
    }
}