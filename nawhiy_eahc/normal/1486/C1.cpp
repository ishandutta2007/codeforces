#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, second;
    cin >> n;
    cout << "? 1 " << n << "\n"; cout.flush();
    cin >> second;

    int l = 1, r = n;
    while(l < r - 2){
        int mid = (l +r)/2, ret;
        if(second < l){
            cout << "? " << second << " " << mid << "\n"; cout.flush();
            cin >> ret;
            if(ret == second) r = mid;
            else l = mid + 1;
        }
        else if(second > r){
            cout << "? " << mid + 1 << " "<< second << "\n"; cout.flush();
            cin >> ret;
            if(ret == second) l = mid + 1;
            else r = mid;
        }

        else if(second <= mid){
            cout << "? " << l << " " << mid << "\n"; cout.flush();
            cin >> ret;
            if(ret == second) r = mid;
            else l = mid + 1;
        }

        else{
            cout << "? " << mid + 1 << " " << r << "\n"; cout.flush();
            cin >> ret;
            if(ret == second) l = mid + 1;
            else r = mid;
        }
    }

    if(l == r - 1){
        cout << "? " << l << " " << r << "\n" ; cout.flush();
        int ret; cin >> ret;
        cout << "! " << l + r - ret << "\n"; cout.flush();
    }

    if(l == r - 2){
        cout << "? " << l << " " << r << "\n"; cout.flush();
        int ret; cin >> ret;
        if(ret == l){
            cout << "? " << l + 1 << " " << l + 2 << "\n"; cout.flush();
            int ans; cin >> ans;
            cout << "! " <<  2*l +3 - ans <<"\n"; cout.flush();
        }
        if(ret == r){
            cout << "? " << l << " " << l +1 << "\n"; cout.flush();
            int ans; cin >> ans;
            cout << "! "<< 2 * l + 1 - ans <<"\n"; cout.flush();
        }

        if(ret == l + 1){
            cout << "? " << l << " " << l + 1 << "\n"; cout.flush();
            int ans; cin >> ans;
            if(ret == ans) cout << "! " << l << "\n";
            else cout << "! " << r << "\n";
        }
    }
}