#include <iostream>
using namespace std;
bool year(int y)
{
    int a[255];
    for(int i=0;i<255;i++)a[i]=0;
    while(y>0)
    {
        a[y%10]++;
        y=y/10;
    }
    int f=0;
    for(int i=0;i<255;i++)
    if(a[i]>1)f=1;
    if(f==0)return true;else return false;
}    
int main()
{
    int y;
    cin>>y;
    y++;
    while(!year(y))
    y++;
    cout<<y;
    return 0;
}