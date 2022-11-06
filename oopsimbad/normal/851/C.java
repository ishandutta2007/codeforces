import java.io.*;
import java.text.*;
import java.util.*;
public class C {
	public static void main(String[] args) throws Exception {
		new C().run();
	}
	public void run() throws Exception {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		int pn = Integer.parseInt(f.readLine());
		Point[] points = new Point[pn];
		for(int i = 0; i < pn; i++) points[i] = new Point(f.readLine());
		boolean[] bad = new boolean[pn];
		int count = 0;
		for(int i = 0; i < pn; i++) {
			boolean good = !bad[i];
			for(int j = 0; good && j < pn; j++) {
				if(i == j) continue;
				for(int k = j + 1; good && k < pn; k++) {
					if(i == k) continue;
					double ang = points[i].ang(points[j], points[k]);
					if(ang >= 90) {
						bad[j] = bad[k] = true;
					} else {
						good = false;
						//System.out.println(i + " x " + j + " " + k);
					}
				}
			}
			if(good)
				count++;
			bad[i] = !good;
		}
		System.out.println(count);
		for(int i = 0; i < pn; i++) if(!bad[i]) System.out.println(i+1);
	}
	class Point {
		int[] co;
		public Point(String s) {
			StringTokenizer st = new StringTokenizer(s);
			co = new int[5];
			for(int i = 0; i < 5; i++)
				co[i] = Integer.parseInt(st.nextToken());
		}
		public double[] vect(Point b) {
			return new double[] {b.co[0] - co[0], b.co[1] - co[1],b.co[2] - co[2],b.co[3] - co[3],b.co[4] - co[4]};
		}
		public double dist(Point a, Point b) {
			double dist = 0;
			for(int i = 0; i < 5; i++) dist += (a.co[i] - b.co[i]) * (a.co[i] - b.co[i]);
			dist = Math.sqrt(dist);
			return dist;
		}
		public double dot(double[] v1, double[] v2) {
			double prod = 0;
			for(int i = 0; i < 5; i++) prod += (v1[i] * v2[i]);
			return prod;
		}
		public double ang(Point b, Point c) {
			double[] v1 = vect(b), v2 = vect(c);
			double ang = Math.acos(dot(v1,v2) / dist(this,b) / dist(this,c));
			return ang * 180 / Math.PI;
		}
	}
}