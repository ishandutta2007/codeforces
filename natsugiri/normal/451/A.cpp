#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

int main() {
    int N, M;
    scanf("%d%d", &N,&M);
    puts( min(N, M) % 2 ?"Akshat" : "Malvika"); 

    return 0;
}