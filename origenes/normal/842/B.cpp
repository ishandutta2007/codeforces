#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int R, d, n, x, y, r, tot=0;
    cin>>R>>d>>n;
    for(int i=0; i<n; i++){
        cin>>x>>y>>r;
        if(2*r>d) continue;
        int tmp=x*x+y*y;
        if((R-d+r)*(R-d+r)<=tmp&&tmp<=(R-r)*(R-r))
            tot++;
    }
    cout<<tot<<endl;
}