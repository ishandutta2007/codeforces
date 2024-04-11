#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long int64;
typedef long double ld;



int main(){
    int n;
    scanf("%d",&n);
    int num=0;
    int add=1;
    for (int i=0;i<n-1;i++){
    num+=add;
    num%=n;
    add++;
    cout<<num+1<<" ";
    }
    cout<<endl;
    return 0;  
}