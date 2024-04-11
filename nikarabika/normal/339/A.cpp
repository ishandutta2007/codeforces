#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    string b;
    cin>>b;
    int size_=(b.size()+1)/2;
    int a[size_];
    for(int i=0; i<b.size(); i+=2)
        a[i/2]=b[i]-48;
    sort(a, a+size_);
    for(int i=0; i<size_-1; i++)
        cout<<a[i]<<'+';
    cout<<a[size_-1]<<endl;
    return 0;
}