#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll a[(size_t)1e5];
int n;

int main() {
    cin>>n;
    for (int i =0 ;i< n; i++)cin>>a[i];
    sort(a,a+n);
    ll bst=1e18;
    for (ll c = 1; ; c++) {
        ll cr = 1, tot = 0;
        bool of = 0;
        for (int i = 0 ;i < n; i++) {
            tot += abs(a[i] - cr);
            if(1e18/c<cr){
                of=1;
                break;
            }
            else cr*=c;
        }
        if(!of)bst=min(bst,tot);
        else break;
    }
    cout<<bst<<endl;
    return 0;
}