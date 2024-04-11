#include <iostream>
#include <string>
using namespace std;
const int a[19]={2, 3, 4, 5, 7, 9, 11, 13, 17, 19, 23, 25, 29, 31, 37, 41, 43, 47, 49};
int main()
{
    int count=0;
    string s;
    cout<<a[0]<<endl;
    for(int i=1; i<20; i++)
    {
        cin>>s;
        if(s=="yes") count++;
        if(count>=2) break;
        if(i<19) cout<<a[i]<<endl;
    }
    if(count<2) cout<<"prime"<<endl;
    else cout<<"composite"<<endl;
    return 0;
}