#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    long long int n, x, k, ptr2, cnt, sa, dm, hm, mid;
    int ptr;
    cnt=0;
    cin >> n >> x >> k;

    int a[n];
    int same[n];
    long long int mod[n+1][2];
    mod[n][1]=0;
    mod[n][0]=4111111111111111111;
    for(int i=0; i<n; i++){
        cin >> a[i];

    }
    sort(a, a + n);

    for(int i=0; i<n; i++){
        mod[i][0]=a[i]/x;
        if(a[i]%x==0){
            mod[i][1]=1;
        }
        else mod[i][1]=0;
    }

    fill(same, same + n, 0);
    ptr=0;

    for(int i=0; i<n; i++){

        sa=0;
        while(1){
            if(mod[ptr][0]-mod[i][0]+mod[i][1]<k){
                ptr++;
            }

            else if(mod[ptr][0]-mod[i][0]+mod[i][1]>k){
                ptr--;
                if(ptr>=0){
                    if(mod[ptr][0]-mod[i][0]+mod[i][1]==k && ptr>=i){
                            dm=ptr-same[ptr]+1;
                            hm=ptr+1;
                            for(int j=0; j<20; j++){
                                mid=(dm+hm)/2;
                                if(a[mid]<a[i]) dm=mid;
                                else hm=mid;
                            }

                            if(a[mid]<a[i]) cnt+=ptr-mid;
                            else cnt+=ptr-mid+1;
                        }
                }
                break;
            }

            else if(mod[ptr][0]-mod[i][0]+mod[i][1]==k){
                sa++;
                if(same[ptr]==0) same[ptr]=sa;
                ptr++;
            }
        }

    }

    cout << cnt;




}