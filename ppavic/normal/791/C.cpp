#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string s;

const int N = 55;

int x = 0,n,k;
int eq[N],a[N];
int cnt = 0;

string sol[55] = {
    "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
    "Aa","Ba","Ca","Da","Ea","Fa","Ga","Ha","Ia","Ja","Ka","La","Ma","Na","Oa","Pa","Qa","Ra","Sa","Ta","Ua","Va","Wa","Xa","Ya","Za",
};

int main() {
    scanf("%d%d",&n,&k);
    for(int i = 0;i<n;i++) a[i] = -1;
    for(int i = 0;i<=n-k;i++){
        cin >> s;
        if(s == "NO"){
            eq[i] = i + k -1;
        }
        else{
            eq[i] = -1;
        }
    }
    for(int i = 0;i<n;i++){
        if(a[i] == -1){
            a[i] = cnt;
            cnt++;
        }
        if(eq[i] != -1){
            a[eq[i]] = a[i];
        }
        cout << sol[a[i]] << " ";
    }
    cout << endl;
}