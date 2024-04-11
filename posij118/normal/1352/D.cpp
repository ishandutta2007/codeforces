#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }

        int aa, bb;
        aa = 0;
        bb = 0;
        int ptr1 = 0;
        int ptr2 = n - 1;
        int last = 0;
        bool frst = 1;
        int cnt = 0;

        bool fin = 0;

        while(1){
            int cur = 0;
            if(frst){
                cnt++;
                while(cur <= last){
                    cur += a[ptr1];
                    ptr1++;

                    if(ptr1 == ptr2 + 1){
                        fin = 1;
                        break;
                    }
                }

                aa += cur;
                last = cur;
                frst ^= 1;

            }

            else{
                cnt++;
                while(cur <= last){
                    cur += a[ptr2];
                    ptr2--;

                    if(ptr1 == ptr2 + 1){
                        fin = 1;
                        break;
                    }
                }

                bb += cur;
                last = cur;
                frst ^= 1;
            }

            if(fin) break;
        }

        cout << cnt << " " << aa << " " << bb << endl;
    }

}