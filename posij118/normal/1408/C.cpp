#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, l;
        cin >> n >> l;

        int a[n + 2];
        for(int i = 0; i<n; i++){
            cin >> a[i + 1];
        }
        a[0] = 0;
        a[n + 1] = l;

        double t = 0;
        int ptr1, ptr2, v1, v2;
        double pos1, pos2;
        ptr1 = 0;
        pos1 = 0;
        pos2 = l;
        ptr2 = n + 1;
        v1 = 1;
        v2 = 1;

        while(ptr1 + 1 < ptr2){
            double t1 = (double)(a[ptr1 + 1] - pos1) / v1;
            double t2 = (double)(pos2 - a[ptr2 - 1]) / v2;

            if(t1 < t2){
                ptr1++;
                v1++;

                pos1 = a[ptr1];
                pos2 -= v2*t1;

                t += t1;
            }

            else{
                ptr2--;
                v2++;

                pos2 = a[ptr2];
                pos1 += v1*t2;

                t += t2;
            }

            //cout << t1 << " " << t2 << endl;
        }

        cout << setprecision(14) << t + (pos2 - pos1) / (v1 + v2) << endl;

    }

}