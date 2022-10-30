#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
string a[100];
int main()
{
    int r, c;
    cin>> r>> c;
    for(int i=0; i<r; ++i){
        cin>> a[i];
    }
    int br=0;
    bool u=false;
    for(int i=0; i<c; ++i){
        if(a[r-1][i]=='B' && !u) {
                u=true;
                br++;
        }
        if(a[r-1][i]=='.') u=false;
    }
    cout << br;
    return 0;
}