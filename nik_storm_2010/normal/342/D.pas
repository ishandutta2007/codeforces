const
  md=1000000007;
  max=3;
var
  a:array[-1..20000,-1..5] of char;
  prv,new:array[0..1 shl max-1] of int64;
  n,lim,ans:int64;
  i,j,x,y:longint;

function bit(num,x:longint):boolean;
begin
  if (num and (1 shl x)>0) then exit(true);
  bit:=false;
end;

function solve:int64;
var
  i,j,k:longint;
begin
  fillchar(prv,sizeof(prv),0);
  prv[lim]:=1;
  for i:=1 to n do for j:=1 to 3 do
  begin
    fillchar(new,sizeof(new),0);
    if (a[i,j]<>'.') then
    begin
      for k:=0 to lim do if (bit(k,2)) then new[(k-4) shl 1+1]:=new[(k-4) shl 1+1]+prv[k];
    end
      else
    begin
      for k:=0 to lim do
      begin
        if (bit(k,2)) then new[(k-4) shl 1]:=new[(k-4) shl 1]+prv[k];
        if (j<>1) and (bit(k,2)) and (not bit(k,0)) then new[(k-4) shl 1+3]:=new[(k-4) shl 1+3]+prv[k];
        if (i<>1) and (not bit(k,2)) then new[k shl 1+1]:=new[k shl 1+1]+prv[k];
      end;
    end;
    for k:=0 to lim do prv[k]:=new[k] mod md;
  end;
  solve:=prv[lim];
end;

procedure rec(nom,cnt:longint);
var
  x1,x2,y1,y2:longint;
begin
  if (nom=5) then
  begin
    if (cnt=0) then exit;
    if (odd(cnt)) then ans:=ans+solve else ans:=ans-solve;
  end
  else
  begin
    case nom of
    1:begin x1:=-1; y1:=0; x2:=-2; y2:=0; end;
    2:begin x1:=0; y1:=+1; x2:=0; y2:=+2; end;
    3:begin x1:=+1; y1:=0; x2:=+2; y2:=0; end;
    4:begin x1:=0; y1:=-1; x2:=0; y2:=-2; end;
    end;
    x1:=x1+x; x2:=x2+x; y1:=y1+y; y2:=y2+y;
    if (a[x1,y1]='.') and (a[x2,y2]='.') then
    begin
      a[x1,y1]:='#'; a[x2,y2]:='#';
      rec(nom+1,cnt+1);
      a[x1,y1]:='.'; a[x2,y2]:='.';
      rec(nom+1,cnt);
    end
      else
    begin
      rec(nom+1,cnt);
    end;
  end;
end;

begin
  readln(n);
  for i:=1 to 3 do
  begin
    for j:=1 to n do
    begin
      read(a[j,i]);
      if (a[j,i]='O') then begin x:=j; y:=i; end;
    end;
    readln;
  end;
  lim:=1 shl max-1;
  rec(1,0);
  while (ans<0) do ans:=ans+md;
  while (ans>=md) do ans:=ans mod md;
  writeln(ans);
end.