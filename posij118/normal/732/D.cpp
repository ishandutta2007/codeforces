#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, dm, hm, mid, ptr, skap;
    cin >> n >> m;

    int d[n];
    for(int i=0; i<n; i++){
        cin >> d[i];
    }

    int a[m];
    for(int i=0; i<m; i++){
        cin >> a[i];
    }

    int dd[n];
    int aa[m];
    vector<int> sorted;
    int used[m];
    dm=0;
    hm=n+1;
    for(int j=0; j<20; j++){
        mid=(dm+hm)/2;
        fill(used, used + m, 0);
        for(int i=0; i<n; i++){
            dd[i]=d[i];
        }
        for(int i=0; i<m; i++){
            aa[i]=a[i];
        }
        sorted.clear();
        skap=0;

        for(int i=mid-1; i>-1; i--){
                if(dd[i]!=0){
                    if(used[dd[i]-1]==0){
                        used[dd[i]-1]=1;
                        sorted.push_back(dd[i]);
                    }

                    else dd[i]=0;
                }
        }

        if(sorted.size()<m){
            dm=mid;
            continue;
        }

        else{
            reverse(sorted.begin(), sorted.end());
            ptr=0;
            for(int i=0; i<mid; i++){
                if(dd[i]==0){
                    aa[sorted[ptr]-1]--;
                    if(aa[sorted[ptr]-1]==0){
                        ptr++;
                        if(ptr==m){
                            skap=1;
                            hm=mid;
                        }
                    }
                }

                else{
                    if(aa[dd[i]-1]!=0){
                        dm=mid;
                        skap=1;
                    }
                }
                if(skap==1) break;
            }
        }

        if(skap==1) continue;
        else hm=mid;
    }

    if(dm>=n) cout << "-1";
    else cout  << hm;


}