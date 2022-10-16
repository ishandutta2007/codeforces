#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int ax,ay,bx,by,cx,cy;
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    if((ax>bx && ax<=cx) || (ax<bx && ax>=cx) || (ay>by && ay<=cy) || (ay<by && ay>=cy))cout<<"NO";
    else cout<<"YES";
    return 0;
}