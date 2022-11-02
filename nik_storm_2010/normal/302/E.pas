var
    i:longint;


begin

  for i:=0 to 9 do writeln('??',i,'>>',i,'??');
  for i:=0 to 8 do writeln(i,'??','<>',i+1);
  writeln('9??>>?0');
  for i:=0 to 8 do writeln(i,'?<>',i+1);
  writeln('9?>>?0');
  writeln('?0<>10');
  writeln('>>??');

end.