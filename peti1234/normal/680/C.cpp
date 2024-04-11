#include <bits/stdc++.h>

using namespace std;

vector<int> prim;
bool p[101];

void prime() {
    for (int i=2; i<101; i++) p[i]=true;

    for (int i=2; i<101; i++){
        if (p[i]){
            prim.push_back(i);
            for (int j=2*i; j<101; j+=i){
                p[j]=false;
            }
        }
    }
}

int main()
{
    prim.push_back(4);
    prim.push_back(9);
    prim.push_back(25);
    prim.push_back(49);
    prime();
    int osztok=0;
    for (int i=0; i<20; i++){
        cout << prim[i] << endl;
        fflush(stdout);
        string valasz;
        cin >> valasz;
        if (valasz=="yes"){
            osztok++;
        }
    }
    if (osztok>=2){
        cout << "composite" << endl;
    }
    else{
        cout << "prime" << endl;
    }
    fflush(stdout);
    return 0;
}