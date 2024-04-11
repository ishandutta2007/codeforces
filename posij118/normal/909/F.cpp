#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, ptr, x,skap;
    skap=0;
    cin >> n;

    int pow[20];
    pow[0]=1;
    for(int i=1; i<20; i++){
        pow[i]=2*pow[i-1];
    }

    if(n%2==1) cout << "NO" << endl;
    else{
        int p[n];
        int used[n+1];
        fill(used+1, used + n+1, 0);
        ptr=n;
        while(ptr>0){
            if(used[ptr]==0){
                for(int i=0; i<20; i++){
                    if(pow[i]-1>ptr){
                        x=pow[i]-1;
                        break;
                    }
                }

                used[ptr]=1;
                used[x-ptr]=1;
                p[ptr-1]=x-ptr;
                p[x-ptr-1]=ptr;

            }

            else ptr--;
        }

        cout << "YES" << endl;
        for(int i=0; i<n; i++){
            cout << p[i] << " ";
        }
        cout << endl;
    }

    for(int i=0; i<20; i++){
        if(n==pow[i]) skap=1;
    }

    if(n<=5) cout << "NO";
    else if(n==6){
        cout << "YES" << endl;
        cout << "3 6 1 5 4 2";
    }

    else if(skap==1) cout << "NO";

    else{
        int bla[]={5, 3, 2, 6, 7, 4, 1};
        vector<int> q (bla, bla + sizeof(bla) / sizeof(int));
        q.resize(n);
        for(int i=8; i<n+1; i++){
            for(int j=19; j>-1; j--){
                if(pow[j]<=i){
                    x=pow[j];
                    break;
                }
            }

            q[i-1]=(i+1)%x+x;
            if(i==n) q[n-1]=x;
        }

        cout << "YES" << endl;
        for(int i=0; i<n; i++){
            cout << q[i] << " ";
        }
        cout << endl;


    }

}