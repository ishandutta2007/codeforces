#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main(){
    int x[3], min=1000;
    cin>>x[0]>>x[1]>>x[2];
    sort(x, x+3);
    for(int i=x[0]; i<=x[2]; i++){
        int tmp=abs(i-x[0])+abs(i-x[1])+abs(i-x[2]);
        if(tmp<min) min=tmp;
    }
    cout<<min<<endl;
    return 0;
}