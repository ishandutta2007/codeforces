#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n,i,j,a,b,l[200],r[200];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i = 1; i<=n; i++){
        cin >> l[i] >> r[i];
    }
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            a = i; b = j;
            while(l[a] != 0) a = l[a];
            while(l[b] != 0) b = l[b];
            if(a != b){
                b = j;
                while(r[b] != 0) b = r[b];
                l[a] = b;
                r[b] = a;
            }
        }
    }
    for(i=1; i<=n; i++)
        cout << l[i] << " " << r[i] << endl;
    return 0;
}