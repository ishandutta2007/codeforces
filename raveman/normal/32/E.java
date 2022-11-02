import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Dictionary;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	public long sq(long x1,long y1,long x2,long y2,long x3,long y3){
		return (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
	}
	public long det(long a,long b,long c,long d){return a*d-b*c;}
	public double det(double a,double b,double c,double d){return a*d-b*c;}
	public boolean inter(long x1,long y1,long x2,long y2,long x3,long y3,long x4,long y4){
		if(Math.max(x1, x2) < Math.min(x3, x4)) return false;
		if(Math.max(y1, y2) < Math.min(y3, y4)) return false;
		if(Math.max(x3, x4) < Math.min(x1, x2)) return false;
		if(Math.max(y3, y4) < Math.min(y1, y2)) return false;

		if(sq(x1,y1,x2,y2,x3,y3)==0 && sq(x1,y1,x2,y2,x4,y4)==0)
			return true;

		long[][] a = new long[2][3];
		a[0][0]= x2-x1;a[0][1]=-(x4-x3);a[0][2]=x3-x1;
		a[1][0]= y2-y1;a[1][1]=-(y4-y3);a[1][2]=y3-y1;
		long d = det(a[0][0],a[0][1],a[1][0],a[1][1]);
		if(d == 0) return false;
		long d1 = det(a[0][2],a[0][1],a[1][2],a[1][1]);
		long d2 = det(a[0][0],a[0][2],a[1][0],a[1][2]);
		if(d<0){
			d=-d;
			d1=-d1;
			d2=-d2;
		}
		if(d1 >= 0 && d1 <= d && d2 >= 0 && d2 <= d) return true;
		return false;
	}
	public double X,Y;
	public boolean inter(long x1,long y1,double x2,double y2,long x3,long y3,long x4,long y4){
		if(Math.max(x1, x2) <= Math.min(x3, x4)) return false;
		if(Math.max(y1, y2) <= Math.min(y3, y4)) return false;
		if(Math.max(x3, x4) <= Math.min(x1, x2)) return false;
		if(Math.max(y3, y4) <= Math.min(y1, y2)) return false;

		double[][] a = new double[2][3];
		a[0][0]= x2-x1;a[0][1]=-(x4-x3);a[0][2]=x3-x1;
		a[1][0]= y2-y1;a[1][1]=-(y4-y3);a[1][2]=y3-y1;
		double d = det(a[0][0],a[0][1],a[1][0],a[1][1]);
		
		if(Math.abs(d) < 1e-9) return false;
		
		double d1 = det(a[0][2],a[0][1],a[1][2],a[1][1]);
		double d2 = det(a[0][0],a[0][2],a[1][0],a[1][2]);
		if(d<0){
			d=-d;
			d1=-d1;
			d2=-d2;
		}
		if(d1 >= 0 && d1 <= d && d2 >= 0 && d2 <= d){
			X = x1 + (x2-x1) * d1/ d;
			Y = y1 + (y2-y1) * d1/ d;
			return true;
		}
		return false;
	}
	
	public boolean good(long x1,long y1,double x2,double y2,long x3,long y3,long x4,long y4){
		return !inter(x1,y1,x2,y2,x3,y3,x4,y4);
	}
	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		
		int xv,yv,xp,yp;
		xv=in.nextInt();yv=in.nextInt();
		xp=in.nextInt();yp=in.nextInt();
		
		int xw1,yw1,xw2,yw2;
		int xm1,ym1,xm2,ym2;
		
		xw1=in.nextInt();yw1=in.nextInt();xw2=in.nextInt();yw2=in.nextInt();
		xm1=in.nextInt();ym1=in.nextInt();xm2=in.nextInt();ym2=in.nextInt();
		boolean f = false;
		
		if(!inter(xv,yv,xp,yp,xw1,yw1,xw2,yw2)){
			if(!inter(xv,yv,xp,yp,xm1,ym1,xm2,ym2)) f = true;
			if(sq(xv,yv,xm1,ym1,xm2,ym2) == 0 && sq(xp,yp,xm1,ym1,xm2,ym2)==0) f = true;
		}
		
		int dx = xm2-xm1;
		int dy = ym2-ym1;
		
		double T  = -2 * (xm1 * dy - ym1 * dx - xp * dy + yp * dx) / (double)(dy * dy + dx * dx);
		double xs = xp - T * dy;
		double ys = yp + T * dx;

		if(Math.signum(sq(xp,yp,xm1,ym1,xm2,ym2)) == Math.signum(sq(xv,yv,xm1,ym1,xm2,ym2)))
		if(sq(xp,yp,xm1,ym1,xm2,ym2)!=0 && inter(xv,yv,xs,ys,xm1,ym1,xm2,ym2))
			if(good(xv,yv,X,Y,xw1,yw1,xw2,yw2) && good(xp,yp,X,Y,xw1,yw1,xw2,yw2)) f = true;

		pw.println(f?"YES":"NO");
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}