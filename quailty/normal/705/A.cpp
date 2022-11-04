#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        printf("%sI %s %s",(i ? " " : ""),(i&1 ? "love" : "hate"),(i<n-1 ? "that" : "it"));
    return 0;
}