#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
#include <stdio.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;

int n,m,k,q,d,h;
ll T;


int main()
{
   int c1,c2,c3,c4,c5,c6;
    int x,y,z;
    int a,b,c,e,t;
    //freopen("test_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    //cin >> n >> q;
    scanf("%d %d" , &n,&q);
    int s = 0;
     b = 0;
    int zp = 0;
     int op = 1;
    for(c1 = 0; c1 < q; c1++){
       // cin >> a;
        scanf("%d",&a);
        if(a == 1){
            scanf("%d",&x);
            zp += x+n;
            op += x+n;
            if(zp >= n){zp %= n;}
            if(op >= n){op %= n;}


        }
        if(a == 2){
            if(zp % 2 == 0){zp++;op += n-1;}
            else{zp += n-1; op++;}
            if(zp >= n){zp %= n;}
            if(op >= n){op %= n;}

            b++;
        }
    }

    s %= n;
    b %= 2;
    std::vector<int> A;

    for(c1 = 0; c1 < n; c1++){
        A.push_back((c1-zp+n)%n);
    }


        c3 = zp;
        for(c1 = 0 ; c1 < n/2; c1++){
            A[c3] = c1*2;
            c3 += 2;
            if(c3 >= n){c3 %= n;}
        }
        c3 = op;
        for(c1 = 0 ; c1 < n/2; c1++){
            A[c3] = c1*2 + 1;
            c3 += 2;
            if(c3 >= n){c3 %= n;}
        }



    for(c1 = 0; c1 < n; c1++){
        //cout << A[c1]+1 << " ";
        printf("%d " , A[c1]+1);
    }

	return 0;
}