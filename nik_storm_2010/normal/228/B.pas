var
    a,b:array[1..100,1..100] of longint; answer,maxx,maxy:longint;
      c:char; tek,na,ma,nb,mb,i,j,x,y:longint;


begin

  readln(na,ma);
  for i:=1 to na do
    begin
      for j:=1 to ma do
        begin
          read(c);
          if c='1' then a[i,j]:=1 else a[i,j]:=0;
        end;
      readln;
    end;
  readln(nb,mb);
  for i:=1 to nb do
    begin
      for j:=1 to mb do
        begin
          read(c);
          if c='1' then b[i,j]:=1 else b[i,j]:=0;
        end;
      readln;
    end;
  answer:=0; maxx:=0; maxy:=0;
  for x:=-50 to 50 do
    for y:=-50 to 50 do
      begin
        tek:=0;
        for i:=1 to na do
          for j:=1 to ma do
          if (1<=i+x) and (i+x<=nb) and (1<=j+y) and (j+y<=mb) then
            begin
              tek:=tek+a[i,j]*b[i+x,j+y];
            end;
        if tek>answer then
          begin
            answer:=tek;
            maxx:=x; maxy:=y;
          end;
      end;
  writeln(maxx,' ',maxy);

end.