#include <iostream>
#include <algorithm>
#define MAX 200000
typedef long long ll;

using namespace std;

int sc[MAX];
int tr[MAX][2];
int max_h = -1, min_h = (1 << 30);

/* useful */
int safe[MAX][2];

int main(){
	int r, c, k, q;
	cin >> r >> c >> k >> q;
	
	/* init of tr[] and max_h */
	for(int i=0;i<r;i++){
		tr[i][0] = tr[i][1] = -1;
	}
	for(int i=0;i<k;i++){
		int r_i, c_i;
		cin >> r_i >> c_i;
		r_i--; c_i--;
		max_h = max(max_h, r_i);
		min_h = min(min_h, r_i);
		if(tr[r_i][0] == -1){
			tr[r_i][0] = tr[r_i][1] = c_i;
			continue;
		}
		tr[r_i][0] = min(tr[r_i][0], c_i);
		tr[r_i][1] = max(tr[r_i][1], c_i);
	}
	
	/* init of safe[]*/
	for(int i=0;i<q;i++){
		cin >> sc[i];
		sc[i]--;
	}
	sort(sc, sc+q);
	int curPos = 0;
	for(int i=0;i<c;i++){
		if(i < sc[0]){
			safe[i][0] = safe[i][1] = sc[0];
			continue;
		}
		if(i >= sc[q-1]){
			safe[i][0] = safe[i][1] = sc[q-1];
			continue;
		}
		if(i < sc[curPos]){
			safe[i][0] = sc[curPos-1];
			safe[i][1] = sc[curPos];
		}else{
			safe[i][0] = safe[i][1] = sc[curPos];
			curPos++;
		}
	}
	
	/* main process */
	ll pos[2][2]; // two cases, (x_pos, step)
	if(min_h == 0){
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				pos[i][j] = tr[0][1];
			}
		}
	}else{
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				pos[i][j] = safe[0][1];
			}
		}
	}

	for(int r_i=max(1, min_h);r_i<r;r_i++){
		if(tr[r_i][0] == -1){
			continue;
		}
		
		ll new_pos[4][2];
		ll Left[2] = {tr[r_i][0], (1LL << 60)}, Right[2] = {tr[r_i][1], (1LL << 60)};
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				new_pos[i*2+j][1] = pos[i][1] + abs(pos[i][0] - safe[pos[i][0]][j]);
				new_pos[i*2+j][0] = safe[pos[i][0]][j];
				// end left
				ll to_left = new_pos[i*2+j][1] + abs(new_pos[i*2+j][0] - tr[r_i][1]) + abs(tr[r_i][1] - tr[r_i][0]);
				ll to_right = new_pos[i*2+j][1] + abs(new_pos[i*2+j][0] - tr[r_i][0]) + abs(tr[r_i][0] - tr[r_i][1]);
				if(Left[1] > to_left){
					Left[1] = to_left;
				}
				if(Right[1] > to_right){
					Right[1] = to_right;
				}
			} 
		}
		pos[0][0] = Left[0];
		pos[0][1] = Left[1];
		pos[1][0] = Right[0];
		pos[1][1] = Right[1];
	}
	cout << min(pos[0][1], pos[1][1]) + max_h;
	return 0;
}