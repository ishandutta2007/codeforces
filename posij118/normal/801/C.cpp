#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    long long int n, p, suma, c, k;
    k=0;
    long double suma2;
    suma=0;
    suma2=0;
    c=0;
    cin >> n >> p;
    long double a[n];
    int b[n];

    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }

    long double sec[n];
    for(int i=0; i<n; i++){
        sec[i]=b[i]/a[i];
    }

    pair <long double, int> pr[n+1];
    pr[0]=make_pair(0, 0);
    for(int i=0; i<n; i++){
        pr[i+1]=make_pair(sec[i], a[i]);
    }

    sort(pr + 1, pr + n + 1);
    for(int i=0; i<n; i++){
        suma+=a[i];
    }

    long double suma3[n+2];
    if(suma<=p) cout << "-1";


    else{
        for(int i=1; i<n+1; i++){
            suma3[i]=suma2;
            suma2+=(pr[i].first-pr[i-1].first)*p;
            suma2-=c*(pr[i].first-pr[i-1].first);

            suma3[i+1]=suma2;
            if(suma2<=0){
                k=i;
                break;
            }

            c+=pr[i].second;
        }

        if(k==0) cout << setprecision(10) << pr[n].first+suma3[n+1]/(c-p) << endl;
        else{
            cout << setprecision(10) << pr[k-1].first+suma3[k]/(c-p) << endl;
        }




    }
}