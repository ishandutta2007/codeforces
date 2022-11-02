const
  lim=100010;
var
   kind,x,y,pos,quest:array[1..2*lim] of int64;
   p,z,cnt:int64;
   m,i,j,n:longint;

begin
  readln(m);
  for i:=1 to m do
  begin
    read(kind[i]);
    if (kind[i]=1) then readln(x[i]) else readln(x[i],y[i]);
  end;
  cnt:=0;
  for i:=1 to m do if (kind[i]=1) then
  begin
    if (cnt=lim) then break;
    inc(cnt);
    pos[cnt]:=x[i];
  end
  else
  begin
    p:=1; z:=y[i];
    while (cnt<lim) do
    begin
      inc(cnt);
      pos[cnt]:=pos[p];
      inc(p);
      if (p>x[i]) then
      begin
        dec(z);
        if (z=0) then break;
        p:=1;
      end;
    end;
  end;
  readln(n);
  for i:=1 to n do read(quest[i]);
  cnt:=0; j:=1;
  for i:=1 to m do
  begin
    if (kind[i]=1) then
    begin
      cnt:=cnt+1;
      while (j<=n) and (quest[j]=cnt) do begin write(x[i],' '); inc(j); end;
    end
    else
    begin
      while (j<=n) and (quest[j]<=cnt+x[i]*y[i]) do
      begin
        z:=quest[j]-cnt;
        if (z mod x[i]=0) then z:=x[i] else z:=z mod x[i];
        write(pos[z],' ');
        inc(j);
      end;
      cnt:=cnt+x[i]*y[i];
    end;
  end;
end.