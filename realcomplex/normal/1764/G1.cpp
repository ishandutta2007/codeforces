#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int query(int li, int ri, int wi){
    cout << "? " << li << " " << ri << " " << wi << endl;
    int res;
    cin >> res;
    return res;
}

int main(){
    int n;
    cin >> n;
    int l = 1;
    int r = n;
    int mid;
    int single1;
    int sz1;
    int single2;
    int sz2;
    while(l < r){
        mid = (l + r) / 2;
        sz1 = mid;
        single1 = 2 * query(1, mid, 2) - sz1;
        sz2 = n - sz1;
        single2 = 2 * query(mid + 1, n, 2) - sz2;
        if(single1 == single2){
            if(mid >= 2){
                if(query(1, mid, n) == 2){
                    l = mid + 1;
                }
                else{
                    r = mid;
                }
            }
            else{
                if(query(mid + 1, n, n) == 2){
                    r = mid;
                }
                else{
                    l = mid + 1;
                }
            }
        }
        else if(single1 > single2){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    cout << "! " << l << endl;
    return 0;
}