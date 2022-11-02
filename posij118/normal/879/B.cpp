#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    long long int k;
    cin >> n >> k;

    pair<int,long long int> cur;
    cur=make_pair(n+1, 0);
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    if(k>500){
        cout << n;
    }

    else{
        while(1){
            if(a[0]>a[1]){
                if(cur.first==a[0]){
                    cur.second++;
                    if(cur.second>=k){
                        cout << cur.first;
                        return 0;
                    }

                    x=a[1];
                    for(int i=2; i<n; i++){
                        a[i-1]=a[i];
                    }
                    a[n-1]=x;
                }

                else{
                    cur=make_pair(a[0], 1);

                    x=a[1];
                   for(int i=2; i<n; i++){
                        a[i-1]=a[i];
                    }
                    a[n-1]=x;
                }
            }

            else{
                cur=make_pair(a[1], 1);
                 x=a[0];
                for(int i=1; i<n; i++){
                        a[i-1]=a[i];
                    }

                    a[n-1]=x;
            }



        }
    }
}