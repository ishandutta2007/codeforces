uses math;
 var
    letter:array[97..122,0..100000] of longint;
     s:ansistring; i,d,pred,j,c:longint;


begin

  readln(s); d:=length(s);
  for i:=1 to d do
    begin
      c:=ord(s[i]); inc(letter[c,0]);
      letter[c,letter[c,0]]:=i;
    end;
  pred:=0;

  for i:=122 downto 97 do
    if letter[i,0]<>0 then
      begin
        for j:=1 to letter[i,0] do
          if pred<letter[i,j] then
            begin
              write(chr(i));
              pred:=letter[i,j];
            end;
      end;

end.