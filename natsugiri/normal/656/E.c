int N, A[11][11];

int main() {
    scanf("%d", &N);

    {
	int ri(int i) {
	    int rj(int j) {
		j < N && ({
			scanf("%d", &A[i][j]);
			rj(j+1);
			});
	    }

	    i < N && ({
		    rj(0);
		    ri(i+1);
		    });
	}
	ri(0);
    }


    {
	int rk(int k) {
	    int ri(int i) { 
		int rj(int j) {
		    j < N && ({
			    A[i][j] > A[i][k] + A[k][j] && (A[i][j] = A[i][k] + A[k][j]);
			    rj(j+1);
			    });
		}

		i < N && ({
			rj(0);
			ri(i+1);
			});
	    }
	    k < N && ({
		    ri(0);
		    rk(k+1);
		    });
	}
	rk(0);
    }


    {
	int ans = 0;
	int ri(int i) {
	    int rj(int j) {
		j < N && ({
			ans < A[i][j] && (ans = A[i][j]);
			rj(j+1);
			});
	    }

	    i < N && ({
		    rj(0);
		    ri(i+1);
		    });
	}
	ri(0);
	printf("%d\n", ans);
    }



    return 0;
}