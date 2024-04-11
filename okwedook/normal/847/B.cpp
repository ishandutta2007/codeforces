#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n,i,j,a[200000],d,k,l,r,m;
vector<int> v[200000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i=0; i<n; i++){
        cin >> a[i];
        l= 0; r = k - 1;
        while(l < r){
            m = (l + r)/2;
            if(a[i] <= v[m][v[m].size() - 1]) l = m + 1;
            else r = m;
        }
        if(k && v[l][v[l].size() - 1] < a[i])
            v[l].push_back(a[i]);
        else{
            v[k].push_back(a[i]);
            k++;
        }
    }
    for(i=0; i<k; i++){
        for(j = 0; j<v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}