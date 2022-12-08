#include <iostream>

using namespace std;

int N, H, L, R;
int M;
int Pa, Ha, Pb, Hb;

int abs(int a){
	return (a<0)?(-a):a;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> H >> L >> R;
	cin >> M;
	while(M--){
		cin >> Pa >> Ha >> Pb >> Hb;
		if(Pa==Pb){
			cout << abs(Ha-Hb) << endl;
		}
		else{
			if(Ha>=L && Ha<=R)
				cout << abs(Ha-Hb)+abs(Pa-Pb) << endl;
			if(Ha<L)
				cout << abs(Ha-L)+abs(Pa-Pb)+abs(Hb-L) << endl;
			if(Ha>R)
				cout << abs(Ha-R)+abs(Pa-Pb)+abs(Hb-R) << endl;
		}
	}
	
	return 0;
}