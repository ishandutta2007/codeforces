#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int n;
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    for(int i=0; i<n/2; i+=2)
        swap(v[i], v[n-i-1]);
    for(int i=0; i<n; i++)
        cout<<v[i]<<' ';
    cout<<endl;
    return 0;
}