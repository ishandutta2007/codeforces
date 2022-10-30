var
    a:array[0..4,0..4] of longint; nom,i,j,c:longint;


procedure light(x,y:longint);
begin
  a[x-1,y]:=1-a[x-1,y];
  a[x+1,y]:=1-a[x+1,y];
  a[x,y-1]:=1-a[x,y-1];
  a[x,y+1]:=1-a[x,y+1];
  a[x,y]:=1-a[x,y];
end;


begin

  for i:=1 to 3 do for j:=1 to 3 do a[i,j]:=1;
  for i:=1 to 3 do
    begin
      for j:=1 to 3 do
        begin
          read(c);
          for nom:=1 to c do light(i,j);
        end;
      readln;
    end;
  for i:=1 to 3 do
    begin
      for j:=1 to 3 do write(a[i,j]);
      writeln;
    end;

end.