#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k;
    scanf("%i %i %i ",&n,&m,&k);
    bool holes[n];
    for(int i = 0;i<n;i++){
        holes[i] = false;
    }
    int s;
    for(int x = 0;x<m;x++){
        scanf("%i",&s);
        s--;
        holes[s] = true;
    }
    int pos = 0;
    int f,se;
    bool swp = true;
    for(int i = 0;i<k;i++){
        scanf("%i %i",&f,&se);
        f--;
        se--;
        if(holes[pos] == true){
            swp = false;
        }
        if(swp == true){
            if(f == pos){
                pos = se;
            }
            else if(se == pos){
                pos = f;
            }
        }
    }
    cout << pos+1;
    return 0;
}