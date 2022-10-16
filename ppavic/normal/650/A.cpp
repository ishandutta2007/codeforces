#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>


using namespace std;

typedef long long int llint ;

int n;
llint sol = 0;
map <int,int > x;
map <int,int> y;
map < pair <int,int> ,int> xy;

int main(){
        scanf("%d",&n);
        int x1,y1;
        for(int i = 0;i<n;i++){
            cin >> x1 >> y1;
            sol -= xy[make_pair(x1,y1)];
            sol += x[x1];sol += y[y1];
            x[x1] ++;
            y[y1]++;
            xy[make_pair(x1,y1)] ++;
        }
        printf("%I64d\n",sol);
}