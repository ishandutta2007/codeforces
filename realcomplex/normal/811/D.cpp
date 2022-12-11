#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

string conf = "UDLR";

int main() {

	map<char,int>val;
	val['*'] = -1;
	val['.'] = 1e9;
	val['F'] = 1e9;;
	int n,m;
	cin >> n >> m;
	char s;
	int sk[n+2][m+2];
	int fp1,fp2;
	for(int i = 0;i<n+2;i++){
        for(int x = 0;x<m+2;x++){
            if(i == 0 || x == 0 || x == m+1 || i == n+1){
                sk[i][x] = -2; // buffer zone...
            }
            else{
                cin >> s;
                sk[i][x] = val[s];
                if(s == 'F'){
                    fp1 = i;
                    fp2 = x;
                }

            }
        }
	}
	int cPos1,cPos2;
	if(sk[1][2] != -1 && sk[2][1] != -1){ // its possible to determine configuration
        cout << "L\n";
        fflush(stdout);
        cin >> cPos1 >> cPos2;
        if(cPos1 == fp1 && cPos2 == fp2){
            return 0;
        }
        if(cPos1 != 1 || cPos2 != 1){
            swap(conf[2],conf[3]);
            cout << "R\n";
            fflush(stdout);
            cin >> cPos1 >> cPos2;

        }
        if(cPos1 == fp1 && cPos2 == fp2){
            return 0;
        }
        cout << "U\n";
        fflush(stdout);
        cin >> cPos1 >> cPos2;
        if(cPos1 == fp1 && cPos2 == fp2){
            return 0;
        }
        if(cPos1 != 1 || cPos2 != 1){
            swap(conf[0],conf[1]);
            cout << "D\n";
            fflush(stdout);
            cin >> cPos1 >> cPos2;

        }
        if(cPos1 == fp1 && cPos2 == fp2){
            return 0;
        }
	}
	else if(sk[1][2] != -1){ // determine if L&R has swapped then find 2*1 empty block
        cout << "L\n";
        fflush(stdout);
        cin >> cPos1 >> cPos2;
        if(cPos1 == fp1 && cPos2 == fp2){
            return 0;
        }
        if(cPos1 != 1 || cPos2 != 1){
            swap(conf[2],conf[3]);
        }
        while(sk[cPos1+1][cPos2] == -1){
            cout << conf[3] << "\n";
            fflush(stdout);
            cin >> cPos1 >> cPos2;
            if(cPos1 == fp1 && cPos2 == fp2){
                return 0;
            }
        }
        cout << "U\n";
        fflush(stdout);
        cin >> cPos1 >> cPos2;
        if(cPos1 == fp1 && cPos2 == fp2){
            return 0;
        }
        if(cPos1 != 1){
            swap(conf[0],conf[1]);
        }

	}
	else{
        cout << "U\n";
        fflush(stdout);
        cin >> cPos1 >> cPos2;
        if(cPos1 == fp1 && cPos2 == fp2){
            return 0;
        }
        if(cPos1 != 1){
            swap(conf[0],conf[1]);
        }
        while(sk[cPos1][cPos2+1] == -1){
            cout << conf[1] << "\n";
            fflush(stdout);
            cin >> cPos1 >> cPos2;
            if(cPos1 == fp1 && cPos2 == fp2){
                return 0;
            }
        }
        cout << "L\n";
        fflush(stdout);
        cin >> cPos1 >> cPos2;
        if(cPos1 == fp1 && cPos2 == fp2){
            return 0;
        }
        if(cPos2 != 1){
            swap(conf[2],conf[3]);
        }
	}
	queue<pair<int,int> >w;
    w.push(make_pair(fp1,fp2));
	int att = 1;
	sk[fp1][fp2] = 0;
	while(w.size() > 0){
        if(sk[w.front().fi+1][w.front().se] > att){
            sk[w.front().fi+1][w.front().se] = att;
            w.push(make_pair(w.front().fi+1,w.front().se));
        }
        if(sk[w.front().fi-1][w.front().se] > att){
            sk[w.front().fi-1][w.front().se] = att;
            w.push(make_pair(w.front().fi-1,w.front().se));
        }
        if(sk[w.front().fi][w.front().se+1] > att){
            sk[w.front().fi][w.front().se+1] = att;
            w.push(make_pair(w.front().fi,w.front().se+1));
        }
        if(sk[w.front().fi][w.front().se-1] > att){
            sk[w.front().fi][w.front().se-1] = att;
            w.push(make_pair(w.front().fi,w.front().se-1));
        }
        att++;
        w.pop();
	}
	while(cPos1 != fp1 || cPos2 != fp2){
        if(sk[cPos1-1][cPos2] >= 0 && sk[cPos1][cPos2] > sk[cPos1-1][cPos2]){
            cout << conf[0] << "\n";
            fflush(stdout);
            cin >> cPos1 >> cPos2;
        }
        else if(sk[cPos1+1][cPos2] >= 0 && sk[cPos1][cPos2] > sk[cPos1+1][cPos2]){
            cout << conf[1] << "\n";
            fflush(stdout);
            cin >> cPos1 >> cPos2;
        }
        else if(sk[cPos1][cPos2-1] >= 0 && sk[cPos1][cPos2] > sk[cPos1][cPos2-1]){
            cout << conf[2] << "\n";
            fflush(stdout);
            cin >> cPos1 >> cPos2;
        }
        else{
            cout << conf[3] << "\n";
            fflush(stdout);
            cin >> cPos1 >> cPos2;
        }
	}
	return 0;
}