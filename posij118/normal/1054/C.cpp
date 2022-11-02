#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, cnt, val, old;
    cnt = 0;
    cin >> n;
    val = n;

    int a[n];
    int l[n];
    int r[n];
    int diffl[n];
    int diffr[n];
    for(int i = 0; i<n; i++){
        cin >> l[i];
    }

    for(int i = 0; i<n; i++){
        cin >> r[i];
    }

    for(int i = 0; i<n; i++){
        a[i] = -1;
    }

    while(cnt < n){
        fill(diffl, diffl + n, 0);
        fill(diffr, diffr + n, 0);
        old = cnt;

        for(int i = 0; i<n; i++){
            if(l[i] == 0 && r[i] == 0 && a[i] == -1){
                cnt++;
                a[i] = val;

                for(int j = 0; j<i; j++){
                    if(l[j] > 0 || r[j] > 0) diffr[j]++;
                }

                for(int j = i+1; j<n; j++){
                    if(l[j] > 0 || r[j] > 0) diffl[j]++;
                }
            }
        }

        if(cnt == n) break;

        for(int i = 0; i<n; i++){
            l[i] = l[i] - diffl[i];

            if(l[i] < 0){
                cout << "NO";
                return 0;
            }

            r[i] = r[i] - diffr[i];

            if(r[i] < 0){
                cout << "NO";
                return 0;
            }

        }

        if(old == cnt){
            cout << "NO";
            return 0;
        }

        val--;
    }

    cout << "YES" << endl;
    for(int i = 0; i<n; i++){
        cout << a[i] << " ";
    }

}