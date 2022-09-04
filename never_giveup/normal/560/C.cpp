#include <bits/stdc++.h>

using namespace std;
int sqr(int x){
    return x*x;
}
int main()
{
    //ifstream cin("in.txt");
    //ofstream cout("out.txt");
    ios::sync_with_stdio(false);
    int a1, a2, a3,a4,a5,a6;
    cin>>a1>>a2>>a3>>a4>>a5>>a6;
    cout<<sqr(a2+a3+a4)-sqr(a2)-sqr(a4)-sqr(a6);
}