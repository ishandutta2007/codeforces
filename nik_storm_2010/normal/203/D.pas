uses math;
var
  vx,vy,vz,t1,t2,t3,ans,a,b,m,x,y,z:extended;


begin
  readln(a,b,m);
  readln(vx,vy,vz);
  x:=a/2; y:=m; z:=0;
  while (y<>0) do
  begin
    if (vx=0) then t1:=maxlongint else if (vx>0) then t1:=(a-x)/vx else t1:=x/(-vx);
    if (vz=0) then t3:=maxlongint else if (vz>0) then t3:=(b-z)/vz else t3:=z/(-vz);
    t2:=(y/(-vy)); ans:=t2;
    ans:=min(ans,t1); ans:=min(ans,t3);
    x:=x+ans*vx; if (x=0) or (x=a) then vx:=-vx;
    y:=y+ans*vy; if (y=0) or (y=m) then vy:=-vy;
    z:=z+ans*vz; if (z=0) or (z=b) then vz:=-vz;
  end;
  writeln(x:0:6,' ',z:0:6);
end.