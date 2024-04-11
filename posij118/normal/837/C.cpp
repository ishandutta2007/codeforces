#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, maxi;
    maxi=0;
    cin >> n >> a >> b;
    int coord[n][2];
    for(int i=0; i<n; i++){
        cin >> coord[i][0] >> coord[i][1];
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(coord[i][0] <= a && coord[i][1] <= b && coord[j][0] <= a && coord[j][1] <= b){
                if((coord[i][0] + coord[j][0]) <= a || (coord[i][1] + coord[j][1]) <= b){
                    maxi=max(maxi, coord[i][0]*coord[i][1] + coord[j][0]*coord[j][1]);
                    continue;
                }
            }

            swap(coord[i][0], coord[i][1]);

            if(coord[i][0] <= a && coord[i][1] <= b && coord[j][0] <= a && coord[j][1] <= b){
                if((coord[i][0] + coord[j][0]) <= a || (coord[i][1] + coord[j][1]) <= b){
                    maxi=max(maxi, coord[i][0]*coord[i][1] + coord[j][0]*coord[j][1]);
                    continue;
                }
            }

            swap(coord[j][0], coord[j][1]);

            if(coord[i][0] <= a && coord[i][1] <= b && coord[j][0] <= a && coord[j][1] <= b){
                if((coord[i][0] + coord[j][0]) <= a || (coord[i][1] + coord[j][1]) <= b){
                    maxi=max(maxi, coord[i][0]*coord[i][1] + coord[j][0]*coord[j][1]);
                    continue;
                }
            }

            swap(coord[i][0], coord[i][1]);

            if(coord[i][0] <= a && coord[i][1] <= b && coord[j][0] <= a && coord[j][1] <= b){
                if((coord[i][0] + coord[j][0]) <= a || (coord[i][1] + coord[j][1]) <= b){
                    maxi=max(maxi, coord[i][0]*coord[i][1] + coord[j][0]*coord[j][1]);
                    continue;
                }
            }


        }
    }

    cout << maxi;

}