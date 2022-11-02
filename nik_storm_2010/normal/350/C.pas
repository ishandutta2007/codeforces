const
  ll=1000000;
var
  kind,help,x,y,z:array[1..ll] of longint;
  dir:array[1..ll] of char;
  ans,n,i:longint;

procedure sort(l,r:longint);
var
  i,j,d,w:longint;
begin
  i:=l; j:=r;
  d:=z[random(r-l+1)+l];
  while (i<=j) do
  begin
    while (z[i]<d) do inc(i);
    while (z[j]>d) do dec(j);
    if (i<=j) then
    begin
      w:=x[i]; x[i]:=x[j]; x[j]:=w;
      w:=y[i]; y[i]:=y[j]; y[j]:=w;
      w:=z[i]; z[i]:=z[j]; z[j]:=w;
      inc(i); dec(j);
    end;
  end;
  if (i<r) then sort(i,r);
  if (l<j) then sort(l,j);
end;

procedure add(x,y:longint;c:char;num:longint);
begin
  kind[num]:=x;
  help[num]:=y;
  dir[num]:=c;
end;

begin
  readln(n);
  for i:=1 to n do
  begin
    readln(x[i],y[i]);
    z[i]:=abs(x[i])+abs(y[i]);
  end;
  randomize;
  sort(1,n);
  ans:=0;
  for i:=1 to n do
  begin
    if (x[i]=0) then
    begin
      if (y[i]>0) then
      begin
        add(1,y[i],'U',ans+1);
        add(1,y[i],'D',ans+3);
      end
        else
      begin
        add(1,-y[i],'D',ans+1);
        add(1,-y[i],'U',ans+3);
      end;
      add(2,0,'$',ans+2);
      add(3,0,'$',ans+4);
      ans:=ans+4;
      continue;
    end;
    if (y[i]=0) then
    begin
      if (x[i]>0) then
      begin
        add(1,x[i],'R',ans+1);
        add(1,x[i],'L',ans+3);
      end
        else
      begin
        add(1,-x[i],'L',ans+1);
        add(1,-x[i],'R',ans+3);
      end;
      add(2,0,'$',ans+2);
      add(3,0,'$',ans+4);
      ans:=ans+4;
      continue;
    end;
    if (x[i]>0) then
    begin
      add(1,x[i],'R',ans+1);
      add(1,x[i],'L',ans+4);
    end
      else
    begin
      add(1,-x[i],'L',ans+1);
      add(1,-x[i],'R',ans+4);
    end;
    if (y[i]>0) then
    begin
      add(1,y[i],'U',ans+2);
      add(1,y[i],'D',ans+5);
    end
      else
    begin
      add(1,-y[i],'D',ans+2);
      add(1,-y[i],'U',ans+5);
    end;
    add(2,0,'$',ans+3);
    add(3,0,'$',ans+6);
    ans:=ans+6;
  end;
  writeln(ans);
  for i:=1 to ans do
  begin
    write(kind[i]);
    if (kind[i]=1) then write(' ',help[i],' ',dir[i]);
    writeln;
  end;
end.