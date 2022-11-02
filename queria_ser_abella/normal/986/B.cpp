#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 2002000
#define debug 
#define mod 998244353
#define pii pair<int,int>

int T[maxn];

void upd(int id){
    while(id < maxn){
        T[id]++;
        id += (id&-id);
    }
}

int qr(int id){
    int r = 0;
    while(id){
        r += T[id];
        id -= (id&-id);
    }
    return r;
}

int v[maxn];

main(){
for(int j=0;j<1;j++){
    memset(T,0,sizeof(T));
   // int n = 1001;
   int n;
   scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",v+i);
        
   
    ll iv = 0;
    for(int i=0;i<n;i++){
     //   cout << v[i] << endl;
        iv += i-qr(v[i]);
        upd(v[i]);
        
    }
    if(iv%2 == n%2)
        printf("Petr\n");
    else
        printf("Um_nik\n");
    return 0;
    cout << iv << endl;
} 
for(int j=0;j<10;j++){memset(T,0,sizeof(T));
    int n = 1001;
    for(int i=0;i<n;i++)
        v[i] = i+1;
        
    for(int i=0;i<7*n+1;i++){
        int a = rand()%n, b = rand()%n;
        if(a == b){
            i--;
            continue;
        }
        swap(v[a],v[b]);
    }
    ll iv = 0;
    for(int i=0;i<n;i++){
     //   cout << v[i] << endl;
        iv += i-qr(v[i]);
        upd(v[i]);
        
    }
    cout << iv << endl;
} 
}