#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e9

void open(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
}

int get(int i,int j){
    cout << "? " << i << " " << j << endl;
    int ans;
    cin >> ans;
    fflush(stdout);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int k[n];
    int s1,s2,s3;
    s1 = get(1,2);
    s2 = get(1,3);
    s3 = get(2,3);
    int l = s1+s2+s3;
    k[2] = (l-(s1*2))/2;
    k[1] = (l-(s2*2))/2;
    k[0] = (l-(s3*2))/2;
    int sum;
    for(int j = 3;j<n;j++){
        sum = get(j,j+1);
        k[j] = sum-k[j-1];
    }
    cout << "! ";
    for(int j = 0;j<n;j++)cout << k[j] << " ";
    return 0;
}