#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, k, q, a, b, c, d, aa, bb, suma;
    cin >> n >> k >> q;
    int recipes[n][2];
    for(int i=0; i<n; i++){
        cin >> recipes[i][0] >> recipes[i][1];
    }

    int que[q][2];
    for(int i=0; i<q; i++){
        cin >> que[i][0] >> que[i][1];
    }

    int pocty[400][501];
    for(int i=0; i<400; i++){
        for(int j=0; j<501; j++){
            pocty[i][j]=0;
        }
    }
    for(int i=0; i<n; i++){
        a=(recipes[i][0]-1)/500;
        aa=a;
        b=(recipes[i][0]-1)%500+1;
        bb=b;
        c=(recipes[i][1]-1)/500;
        d=(recipes[i][1]-1)%500+1;
        while(a!=c || b!=d){
            if(a==c && b>0){
                pocty[a][b]++;
                b++;
            }

            else if(a==c && b==0) b++;

            else if(a==aa && b==500){
                    pocty[a][b]++;
                    a++;
                    b=0;
            }

            else if(b==0){
                pocty[a][b]++;
                a++;
            }

            else{
                pocty[a][b]++;
                b++;
            }
        }

        pocty[c][d]++;
    }

    int pocty2[400][501];
    for(int i=0; i<400; i++){
        for(int j=0; j<501; j++){
            pocty2[i][j]=0;
        }
    }

    for(int i=0; i<400; i++){
        for(int j=1; j<501; j++){
            if(pocty[i][j]+pocty[i][0]>=k){
                pocty2[i][j]=1;
                pocty2[i][0]++;
            }
        }
    }

    for(int i=0; i<q; i++){
        a=(que[i][0]-1)/500;
        aa=a;
        b=(que[i][0]-1)%500+1;
        bb=b;
        c=(que[i][1]-1)/500;
        d=(que[i][1]-1)%500+1;
        suma=0;
        while(a!=c || b!=d){
            if(a==c && b>0){
                suma+=pocty2[a][b];
                b++;
            }

            else if(a==c && b==0) b++;

            else if(a==aa && b==500){
                suma+=pocty2[a][b];
                a++;
                b=0;
            }

            else if(b==0){
                suma+=pocty2[a][b];
                a++;
            }

            else{
                suma+=pocty2[a][b];
                b++;
            }
        }

        suma+=pocty2[a][b];
        cout << suma << endl;


    }
}