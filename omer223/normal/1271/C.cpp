#include <iostream>

using namespace std;
const int sz=2e5+5;
int dir[4];//nsew
int main() {
    int n,x,y, a, b;
    cin>>n>>x>>y;
    for(int i =0;i<n;i++){
        cin>>a>>b;
        if(a!=x){
            if(a>x)dir[2]++;
            else dir[3]++;
        }
        if(b!=y){
            if(b>y)dir[0]++;
            else dir[1]++;
        }
    }
    int mx=0,mxi=-1;
    for(int i =0;i<4;i++){
        if(dir[i]>mx){
            mx=dir[i];
            mxi=i;
        }
    }
    cout<<mx<<endl;
    switch(mxi){
        case 0:
        cout<<x<<" "<<y+1<<endl;
        break;
        case 1:
        cout<<x<<" "<<y-1<<endl;
        break;
        case 2:
        cout<<x+1<<" "<<y<<endl;
        break;
        case 3:
        cout<<x-1<<" "<<y<<endl;
        break;
    }
}