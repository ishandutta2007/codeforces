var
    b:array[1..100,1..100] of longint; tek,n,i,j:longint;


begin

  readln(n);
  for i:=1 to n do
    begin
      for j:=1 to n do read(b[i,j]);
      readln;
    end;
  for i:=1 to n do
    begin
      tek:=0;
      for j:=1 to n do
        if i<>j then tek:=tek or b[i,j];
      write(tek,' ');
    end;

end.