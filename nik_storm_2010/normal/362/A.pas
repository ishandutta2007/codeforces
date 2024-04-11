var
  a:array[1..8,1..8] of char;
  l:array[1..2,1..8,1..8] of longint;
  q:array[1..4,1..1000] of longint;
  i,x,y,test,x1,x2,y1,y2,qs,qf,nom,leng:longint;
  maybe:boolean;

procedure add(x,y,nom,leng:longint);
begin
  if (x<1) or (x>8) or (y<1) or (y>8) or (l[nom,x,y]<>-1) then exit;
  if (l[nom,x,y]<>-1) and (l[nom,x,y]<leng) then exit;
  l[nom,x,y]:=leng;
  q[1,qf]:=x;
  q[2,qf]:=y;
  q[3,qf]:=nom;
  q[4,qf]:=leng;
  inc(qf);
end;

procedure outt(var x,y,nom,leng:longint);
begin
  x:=q[1,qs];
  y:=q[2,qs];
  nom:=q[3,qs];
  leng:=q[4,qs];
  inc(qs);
end;

begin
  readln(test);
  for i:=1 to test do
  begin
    x1:=-1;
    x2:=-1;
    for x:=1 to 8 do for y:=1 to 8 do begin l[1,x,y]:=-1; l[2,x,y]:=-1; end;
    for x:=1 to 8 do
    begin
      for y:=1 to 8 do
      begin
        read(a[x,y]);
        if (a[x,y]='K') then
        begin
          if (x1=-1) then
          begin
            x1:=x;
            y1:=y;
          end
            else
          begin
            x2:=x;
            y2:=y;
          end;
        end;
      end;
      readln;
    end;
    qs:=1;
    qf:=1;
    add(x1,y1,1,0);
    while (qs<>qf) do
    begin
      outt(x1,y1,nom,leng);
      add(x1+2,y1+2,nom,leng+1);
      add(x1+2,y1-2,nom,leng+1);
      add(x1-2,y1+2,nom,leng+1);
      add(x1-2,y1-2,nom,leng+1);
    end;
    qs:=1;
    qf:=1;
    add(x2,y2,2,0);
    while (qs<>qf) do
    begin
      outt(x1,y1,nom,leng);
      add(x1+2,y1+2,nom,leng+1);
      add(x1+2,y1-2,nom,leng+1);
      add(x1-2,y1+2,nom,leng+1);
      add(x1-2,y1-2,nom,leng+1);
    end;
    maybe:=false;
    for x:=1 to 8 do for y:=1 to 8 do
    begin
      if (a[x,y]='#') then continue;
      if (l[1,x,y]=-1) or (l[2,x,y]=-1) then continue;
      if (odd(l[1,x,y])=odd(l[2,x,y])) then
      begin
        maybe:=true;
        break;
      end;
    end;
    if (maybe) then writeln('YES') else writeln('NO');
    if (i<>test) then readln;
  end;
end.